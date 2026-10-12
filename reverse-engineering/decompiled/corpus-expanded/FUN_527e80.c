/* Ghidra pseudocode, not original source.
 * ev_856f9c42d20ec6ba6350b0d1cce9335bfe45cee30263bcd63df252d3cb890b58
 * Entry: 0x527e80; label: FUN_00527e80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00527e80(int param_1)

{
  char cVar1;
  int in_EAX;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  float local_4c;
  undefined4 local_48;
  float local_44;
  undefined1 local_40 [64];
  
  cVar1 = *(char *)(in_EAX + 0x49);
  if (cVar1 == '\0') {
    if (param_1 != 0) {
      FUN_0051f720(in_EAX + 8,*(undefined4 *)(in_EAX + 0x14),
                   *(float *)(in_EAX + 0x18) + *(float *)(in_EAX + 0xc),
                   *(float *)(in_EAX + 0x1c) + *(float *)(in_EAX + 0xc));
      return;
    }
    FUN_0051fab0(in_EAX + 8,*(undefined4 *)(in_EAX + 0x14));
  }
  else {
    if (cVar1 == '\x01') {
      if (param_1 != 0) {
        FUN_0051f8c0(in_EAX + 8,*(undefined4 *)(in_EAX + 0x40),*(undefined4 *)(in_EAX + 0x44),
                     *(undefined4 *)(in_EAX + 0x3c),
                     *(float *)(in_EAX + 0x18) + *(float *)(in_EAX + 0xc),
                     *(float *)(in_EAX + 0x1c) + *(float *)(in_EAX + 0xc));
        return;
      }
      FUN_0051f8c0(in_EAX + 8,*(undefined4 *)(in_EAX + 0x40),*(undefined4 *)(in_EAX + 0x44),
                   *(undefined4 *)(in_EAX + 0x3c),*(undefined4 *)(in_EAX + 0xc),
                   *(undefined4 *)(in_EAX + 0xc));
      return;
    }
    if (cVar1 == '\x02') {
      FUN_005b4500(local_40,in_EAX + 8);
      FUN_005b5060(local_40,*(undefined4 *)(in_EAX + 0x3c));
      local_4c = -*(float *)(in_EAX + 0x40);
      local_48 = *(undefined4 *)(in_EAX + 0x18);
      local_44 = -*(float *)(in_EAX + 0x44);
      local_58 = *(undefined4 *)(in_EAX + 0x40);
      local_54 = *(undefined4 *)(in_EAX + 0x1c);
      local_50 = *(undefined4 *)(in_EAX + 0x44);
      if (param_1 == 0) {
        local_54 = 0;
        local_48 = 0;
      }
      FUN_005dc9f0(&local_4c,&local_58,local_40);
      return;
    }
  }
  return;
}

