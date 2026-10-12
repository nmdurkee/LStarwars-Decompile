/* Ghidra pseudocode, not original source.
 * ev_2c33bc1d2955cf32f461d40ab407fc477c117f7bb728ceb3ddb2ece88215ba87
 * Entry: 0x4c9f60; label: FUN_004c9f60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004c9f60(uint *param_1,undefined4 param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  uint *in_ECX;
  
  uVar2 = *param_1 + 0xf & 0xfffffff0;
  *param_1 = uVar2;
  *in_ECX = uVar2;
  *param_1 = *param_1 + param_3;
  puVar1 = in_ECX + 1;
  *puVar1 = *param_1;
  in_ECX[2] = (uint)in_ECX;
  in_ECX[3] = (uint)puVar1;
  in_ECX[5] = 0;
  in_ECX[6] = *puVar1 - *in_ECX;
  in_ECX[4] = 0;
  _memset(in_ECX + 7,0,0x22c);
  return;
}

