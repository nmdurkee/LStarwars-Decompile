/* Ghidra pseudocode, not original source.
 * ev_a5c3a3c7ef2e1a12e467fd0202ed50a9ce8374cc5ec0bfb4f993dbf776f2abbe
 * Entry: 0x419e00; label: FUN_00419e00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00419e00(int param_1)

{
  undefined4 uVar1;
  undefined4 local_c;
  float local_8;
  float local_4;
  
  if (param_1 == 0) {
    local_4 = 0.0;
    local_c = 0;
    local_8 = -_DAT_007f239c * 0.25;
  }
  else {
    local_c = 0x47800000;
    local_8 = *(float *)(param_1 + 0x84);
    local_4 = *(float *)(param_1 + 0x21c) - 0.1;
  }
  if (DAT_00951288 == 0) {
    uVar1 = 0x41f00000;
  }
  else {
    uVar1 = 0x43160000;
  }
  FUN_005f9980(&local_c,0x17000000,uVar1,uVar1);
  return;
}

