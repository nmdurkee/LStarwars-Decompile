/* Ghidra pseudocode, not original source.
 * ev_57ca11fd66234800334e5f23d40b47e1bf5f9001c22ff37fd2f45222df4b5a02
 * Entry: 0x603200; label: FUN_00603200
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00603200(byte *param_1,byte *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (((*param_1 == 0) && (param_1[1] == 0)) && (param_1[2] == 0)) {
    uVar1 = (uint)*param_2;
    uVar2 = uVar1;
    uVar3 = uVar1;
  }
  else {
    uVar1 = (uint)param_2[*param_1] + param_3;
    uVar3 = (uint)param_2[param_1[1]] + param_3;
    uVar2 = (uint)param_2[param_1[2]] + param_3;
  }
  if (0xff < (int)uVar1) {
    uVar1 = 0xff;
  }
  if (0xff < (int)uVar3) {
    uVar3 = 0xff;
  }
  if (0xff < (int)uVar2) {
    uVar2 = 0xff;
  }
  if ((int)uVar1 < 0) {
    uVar1 = 0;
  }
  if ((int)uVar3 < 0) {
    uVar3 = 0;
  }
  if ((int)uVar2 < 0) {
    uVar2 = 0;
  }
  *param_1 = (byte)uVar1;
  param_1[1] = (byte)uVar3;
  param_1[2] = (byte)uVar2;
  return;
}

