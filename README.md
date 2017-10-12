
# konnichiha

项目名为`konnichiha`，即为日文(こんにちは)，也就是中文的你好，该技能是 RokidOS 提供给开发者的
本地技能示例程序，程序使用 C/C++ 编写。

## 入口词

使用“打开技能演示”进入应用。

## 特性

- [x] 生命周期
- [x] 语音合同
- [ ] 媒体播放
- [ ] 其他播放

## 如何使用

通过 RokidOS 镜像中编译出应用程序后，放到 `/opt/apps/` 或 `/data/apps` 下，另外，需要特别注意
`package.json` 也必须出现在相同目录，并且必须包含以下字段：

```json
  "metadata": {
    "type": "cut",
    "skills": [
      "RBB469857DC043048807C2951EF021FB"
    ],
    "native": true
  }
```

- `type` 可支持 `cut` 和 `scene`，具体参看 Rokid 官方文档对应用生命周期的定义
- `skills` 为一个 ID 数组，可在 Rokid 开发者后台创建技能后获取，表示该应用可以处理的技能，原则上来
  说，应该一个应用对应一个 `Skill`，不过我们也支持使用同一个应用来处理不同 `Skill` 的情况。
- `native` 布尔值，表示这里是否是 native 应用，这里的 native 指的是是否该技能是以独立应用的方式来
  运行的，与此相对应的我们还有轻应用(lightapp)的概念，轻应用只是一个 JavaScript 脚本，直接用于一些
  快速简单的技能。

另外注意在 `package.json` 中的 `main` 字段也很重要，他表示我们的 `VUI` 系统将如何启动你的应用程序，
如在本例中，我们编译好的程序叫：`app`，则我们指定如下：

```json
  "main": "app",
  ...
```

## License

MIT