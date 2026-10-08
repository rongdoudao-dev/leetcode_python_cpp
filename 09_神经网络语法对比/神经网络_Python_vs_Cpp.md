# 神经网络 Python vs C++ 语法对比

## 一、张量操作对比

| 操作 | Python (PyTorch) | C++ (LibTorch) | 说明 |
|------|------------------|-----------------|------|
| 创建张量 | `torch.tensor([1,2,3])` | `torch::tensor({1,2,3})` | 语法几乎一致 |
| 全0张量 | `torch.zeros(3,4)` | `torch::zeros({3,4})` | C++用大括号包尺寸 |
| 全1张量 | `torch.ones(3,4)` | `torch::ones({3,4})` | 同上 |
| 随机张量 | `torch.randn(3,4)` | `torch::randn({3,4})` | 标准正态分布 |
| 查看形状 | `tensor.shape` | `tensor.sizes()` | Python属性 vs C++方法 |
| 查看维度 | `tensor.dim()` | `tensor.dim()` | 一致 |
| 改变形状 | `tensor.view(3,4)` | `tensor.view({3,4})` | C++大括号 |
| 改变形状 | `tensor.reshape(3,4)` | `tensor.reshape({3,4})` | 同上 |
| 转置 | `tensor.t()` | `tensor.t()` | 一致 |
| 矩阵乘法 | `a @ b` 或 `torch.mm(a,b)` | `torch::mm(a,b)` | Python有@运算符 |
| 元素乘 | `a * b` | `a * b` | 一致 |
| 求和 | `tensor.sum()` | `tensor.sum()` | 一致 |
| 求均值 | `tensor.mean()` | `tensor.mean()` | 一致 |
| 最大值 | `tensor.max()` | `tensor.max()` | 一致 |
| 索引 | `tensor[0,1]` | `tensor[0][1]` 或 `tensor.index({0,1})` | C++更繁琐 |
| 切片 | `tensor[:, 0:5]` | `tensor.index({"...", Slice(0,5)})` | C++用Slice类 |
| GPU迁移 | `tensor.cuda()` | `tensor.to(torch::kCUDA)` | C++用枚举 |
| CPU迁移 | `tensor.cpu()` | `tensor.to(torch::kCPU)` | 同上 |
| 转numpy | `tensor.numpy()` | 无（需手动拷贝） | C++没有numpy |
| 取Python值 | `tensor.item()` | `tensor.item<float>()` | C++需指定类型 |

## 二、模型定义对比

### Python (PyTorch)
```python
import torch
import torch.nn as nn

class SimpleNet(nn.Module):
    def __init__(self, input_size, hidden_size, output_size):
        super().__init__()
        self.fc1 = nn.Linear(input_size, hidden_size)
        self.relu = nn.ReLU()
        self.fc2 = nn.Linear(hidden_size, output_size)

    def forward(self, x):
        x = self.fc1(x)
        x = self.relu(x)
        x = self.fc2(x)
        return x
```

### C++ (LibTorch)
```cpp
#include <torch/torch.h>

struct SimpleNet : torch::nn::Module {
    torch::nn::Linear fc1{nullptr};
    torch::nn::Linear fc2{nullptr};

    SimpleNet(int input_size, int hidden_size, int output_size) {
        fc1 = register_module("fc1", torch::nn::Linear(input_size, hidden_size));
        fc2 = register_module("fc2", torch::nn::Linear(hidden_size, output_size));
    }

    torch::Tensor forward(torch::Tensor x) {
        x = torch::relu(fc1->forward(x));
        x = fc2->forward(x);
        return x;
    }
};
```

### 关键差异

| 对比项 | Python | C++ |
|--------|--------|-----|
| 继承 | `class Net(nn.Module)` | `struct Net : torch::nn::Module` |
| 构造函数 | `def __init__` | 与类同名的构造函数 |
| 调用父类 | `super().__init__()` | 不需要（自动调用） |
| 注册层 | 直接赋值 `self.fc1 = nn.Linear(...)` | `register_module("fc1", ...)` |
| 层类型 | `nn.Linear` | `torch::nn::Linear` |
| 前向传播 | `def forward(self, x)` | `torch::Tensor forward(torch::Tensor x)` |
| 调用层 | `self.fc1(x)` | `fc1->forward(x)` |
| 激活函数 | `nn.ReLU()` 或 `F.relu(x)` | `torch::relu(x)` |
| 实例化 | `model = SimpleNet(784, 128, 10)` | `SimpleNet model(784, 128, 10);` |
| 模型迁移GPU | `model.cuda()` | `model->to(torch::kCUDA);` |

## 三、训练循环对比

### Python (PyTorch)
```python
import torch
import torch.nn as nn
import torch.optim as optim

model = SimpleNet(784, 128, 10)
criterion = nn.CrossEntropyLoss()
optimizer = optim.Adam(model.parameters(), lr=0.001)

for epoch in range(10):
    for images, labels in train_loader:
        images = images.view(-1, 784)
        optimizer.zero_grad()
        outputs = model(images)
        loss = criterion(outputs, labels)
        loss.backward()
        optimizer.step()
```

### C++ (LibTorch)
```cpp
#include <torch/torch.h>

SimpleNet model(784, 128, 10);
torch::nn::CrossEntropyLoss criterion;
torch::optim::Adam optimizer(model.parameters(), torch::optim::AdamOptions(0.001));

for (int epoch = 0; epoch < 10; epoch++) {
    for (auto& batch : train_loader) {
        auto images = batch.data.view({-1, 784});
        auto labels = batch.target;
        optimizer.zero_grad();
        auto outputs = model.forward(images);
        auto loss = criterion(outputs, labels);
        loss.backward();
        optimizer.step();
    }
}
```

### 关键差异

| 对比项 | Python | C++ |
|--------|--------|-----|
| 损失函数 | `nn.CrossEntropyLoss()` | `torch::nn::CrossEntropyLoss criterion;` |
| 优化器 | `optim.Adam(model.parameters(), lr=0.001)` | `torch::optim::Adam optimizer(model.parameters(), torch::optim::AdamOptions(0.001));` |
| 梯度清零 | `optimizer.zero_grad()` | `optimizer.zero_grad();` |
| 前向计算 | `outputs = model(images)` | `auto outputs = model.forward(images);` |
| 计算损失 | `loss = criterion(outputs, labels)` | `auto loss = criterion(outputs, labels);` |
| 反向传播 | `loss.backward()` | `loss.backward();` |
| 参数更新 | `optimizer.step()` | `optimizer.step();` |
| 遍历数据 | `for images, labels in loader:` | `for (auto& batch : loader) { auto data = batch.data; auto target = batch.target; }` |

## 四、卷积层对比

| 操作 | Python | C++ |
|------|--------|-----|
| 定义卷积 | `nn.Conv2d(1, 16, 3, padding=1)` | `torch::nn::Conv2d(torch::nn::Conv2dOptions(1, 16, 3).padding(1))` |
| 定义池化 | `nn.MaxPool2d(2)` | `torch::nn::MaxPool2d(torch::nn::MaxPool2dOptions(2))` |
| 定义全连接 | `nn.Linear(128, 10)` | `torch::nn::Linear(128, 10)` |
| 定义Dropout | `nn.Dropout(0.5)` | `torch::nn::Dropout(0.5)` |
| 定义BatchNorm | `nn.BatchNorm2d(16)` | `torch::nn::BatchNorm2d(16)` |
| 前向调用 | `x = self.conv1(x)` | `x = conv1->forward(x);` |

## 五、模型保存加载对比

### Python
```python
# 保存
torch.save(model.state_dict(), 'model.pth')
# 加载
model.load_state_dict(torch.load('model.pth'))
```

### C++
```cpp
// 保存
torch::save(model, "model.pt");
// 加载
torch::load(model, "model.pt");
```

## 六、面试高频考点

1. **PyTorch动态图 vs TensorFlow静态图**：PyTorch每次forward重新构建计算图，调试方便
2. **autograd自动求导**：`requires_grad=True`的参数会自动计算梯度
3. **loss.backward()**：反向传播，计算所有参数梯度
4. **optimizer.step()**：根据梯度更新参数
5. **optimizer.zero_grad()**：清零梯度，防止累积
6. **DataLoader**：自动批处理、打乱、多线程加载
7. **nn.Sequential**：顺序容器，快速搭建简单模型
8. **nn.ModuleList**：模块列表，可索引
9. **register_buffer**：注册不需要梯度的参数（如running_mean）
10. **torch.no_grad()**：推理时关闭梯度计算，节省内存
