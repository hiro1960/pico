#include <fstream>
#include <map>
#include <picojson.h>

int main(int argc, char** argv)
{
  picojson::value v;
  std::ifstream infile;

  // read json value from stream
  //std::cin >> v;
  infile.open(argv[1]);
  infile >> v;
  infile.close();

  if (std::cin.fail()) {
    std::cerr << picojson::get_last_error() << std::endl;
    return 1;
  }
  
  // dump json object
  std::cout << "---- dump input ----" << std::endl;
  std::cout << v << std::endl;

  // accessors
  std::cout << "---- analyzing input ----" << std::endl;
  if (v.is<picojson::null>()) {
    std::cout << "input is null" << std::endl;
  } else if (v.is<bool>()) {
    std::cout << "input is " << (v.get<bool>() ? "true" : "false") << std::endl;
  } else if (v.is<double>()) {
    std::cout << "input is " << v.get<double>() << std::endl;
  } else if (v.is<std::string>()) {
    std::cout << "input is " << v.get<std::string>() << std::endl;
  } else if (v.is<picojson::array>()) {
    std::cout << "input is an array" << std::endl;
    const picojson::array& a = v.get<picojson::array>();
    for (picojson::array::const_iterator i = a.begin(); i != a.end(); ++i) {
      std::cout << "  " << *i << std::endl;
    }
  } else if (v.is<picojson::object>()) {
    std::cout << "input is an object" << std::endl;
    //const picojson::object& o = v.get<picojson::object>();
    picojson::object& o = v.get<picojson::object>();
    for (picojson::object::const_iterator i = o.begin(); i != o.end(); ++i) {
      std::cout << i->first << "  " << i->second << std::endl;
    }
    
    std::cout << std::endl;

    // 一番外側のobjectの取得
    std::string& s1 = o["message"].get<std::string>();
    //picojson::array& s1 = o["number"].get<picojson::array>();
    std::cout << s1 << std::endl;

    std::cout << std::endl;

    // 値の変更
    o["message"] = (picojson::value)std::string("fail");

    // データの追加
    o.insert(std::map<std::string, double>::value_type("piyopiyo", 10.0));

    for (picojson::object::const_iterator i = o.begin(); i != o.end(); ++i) {
      std::cout << i->first << "  " << i->second << std::endl;
    }
    
    std::cout << std::endl;

    // 内部のobject値の取得
    picojson::object& o1 = o["person"].get<picojson::object>();
    std::cout << o1["name"].get<std::string>() << " " << o1["age"].get<double>() << std::endl;

    std::cout << std::endl;

    // array値の取得
    picojson::array& a1 = o["follow"].get<picojson::array>();
    o1 = a1[1].get<picojson::object>();
    std::cout << o1["name"].get<std::string>() << " " << o1["age"].get<double>() << std::endl;

    std::cout << std::endl;

    // serialize（JSON形式の文字列に戻す。JavaScriptのstringify()と同じ。）
    std::string str = picojson::value(o).serialize();
    std::cout << str << std::endl;

  }
  
  return 0;
}
