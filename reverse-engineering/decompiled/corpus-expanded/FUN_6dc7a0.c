/* Ghidra pseudocode, not original source.
 * ev_3968740630932d2cb6945455b13b10dc603e92ef7b36def715db8f60cd47147a
 * Entry: 0x6dc7a0; label: FUN_006dc7a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006dc7a0(char param_1)

{
  undefined4 local_28;
  uint local_24;
  undefined4 local_20;
  uint local_1c;
  undefined4 local_18;
  uint local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (param_1 != '\0') {
    SystemParametersInfoA(0x3b,8,&DAT_0082763c,0);
    SystemParametersInfoA(0x35,8,&DAT_00827644,0);
    SystemParametersInfoA(0x33,0x18,&DAT_0082764c,0);
    return;
  }
  local_28 = DAT_0082763c;
  local_24 = DAT_00827640;
  if ((DAT_00827640 & 1) == 0) {
    local_24 = DAT_00827640 & 0xfffffff3;
    SystemParametersInfoA(0x3b,8,&local_28,0);
  }
  local_20 = DAT_00827644;
  local_1c = DAT_00827648;
  if ((DAT_00827648 & 1) == 0) {
    local_1c = DAT_00827648 & 0xfffffff3;
    SystemParametersInfoA(0x35,8,&local_20,0);
  }
  local_18 = DAT_0082764c;
  local_10 = DAT_00827654;
  local_c = DAT_00827658;
  local_8 = DAT_0082765c;
  local_4 = DAT_00827660;
  if ((DAT_00827650 & 1) == 0) {
    local_14 = DAT_00827650 & 0xfffffff3;
    SystemParametersInfoA(0x33,0x18,&local_18,0);
  }
  return;
}

