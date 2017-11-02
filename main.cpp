#include <ams/rknative.h>
#include <tts/tts_client.h>

/**
 * @class ExampleApp
 */
class ExampleApp : public NativeBase {
 public:
  /**
   * @method constructor
   */
  ExampleApp(const char* name) : NativeBase(name) {}
  /**
   * @method onCreate
   */
  bool onCreate(const std::string& ctx) {
    fprintf(stdout, "received the <create> event\n");
    return true;
  }
  /**
   * @method onRestart
   */
  bool onRestart(const std::string& ctx) {
    fprintf(stdout, "received the <restart> event\n");
    return true;
  }
  /**
   * @method onRevival
   */
  bool onRevival(const std::string& ctx) {
    // not used
    return true;
  }
  /**
   * @method onResume
   */
  bool onResume() {
    fprintf(stdout, "received the <resume> event\n");
    return true;
  }
  /**
   * @method onPause
   */
  bool onPause() {
    fprintf(stdout, "received the <pause> event\n");
    return true;
  }
  /**
   * @method onStop
   */
  bool onStop() {
    fprintf(stdout, "received the <stop> event\n");
    return true;
  }
  /**
   * @method onDestroy
   */
  bool onDestroy() {
    fprintf(stdout, "received the <destroy> event\n");
    tts_cancel(tts_task_id, NULL);
    exit(0);
    return true;
  }
  /**
   * @method onRapture
   */
  bool onRapture() {
    // not used
    return true;
  }
  /**
   * @method onEvent
   */
  bool onEvent(const std::string& event) {
    fprintf(stdout, "received the <event> event: %s\n", event.c_str());
    return true;
  }
  /**
   * @method onVoiceCommand
   */
  bool onVoiceCommand(const std::string& asr, const std::string& nlp, const std::string& action) {
    fprintf(stdout, "received the <voice_command> event: %s %s\n", asr.c_str(), nlp.c_str());
    tts_task_id = tts_speak("正在为您演示若琪的语音合成技术!首先需要使用 init 函数进行初始化，然后就能使用 speak 函数正常调用了！", NULL);
    printf("send ttsflinger done\n");
    return true;
  }
 
 private:
  int tts_task_id;
};

int main(int argc, char const *argv[]) {
  const char* appid = argv[1];
  fprintf(stdout, "appid: <%s>\n", appid);
  tts_init();
  NativeBase* client = static_cast<NativeBase*>(new ExampleApp(appid));
  client->Enter();
  return 0;
}
