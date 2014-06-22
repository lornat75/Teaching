#memory.thrift
service Memory {
  string get_answer(string k);
  bool push(string k string v);
  bool show_list();
  bool clear();
}