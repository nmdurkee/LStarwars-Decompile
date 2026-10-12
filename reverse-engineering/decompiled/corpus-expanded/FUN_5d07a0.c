/* Ghidra pseudocode, not original source.
 * ev_2a2c0e65abfb9c10d1e5708a86db983babfd8b559b68eb98bb3f20c083d0e5d5
 * Entry: 0x5d07a0; label: FUN_005d07a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_005d07a0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar4 = param_3 + 0xc;
  if (param_3 == 0) {
    uVar4 = *(uint *)(param_1 + 0x34);
  }
  iVar1 = *(int *)(param_1 + 0x30);
  iVar2 = *(int *)(param_1 + 0x34);
  while( true ) {
    if ((uint)(iVar2 + iVar1 * 0xc) <= uVar4) {
      return 0;
    }
    iVar3 = FUN_004f8b80(param_2,*(undefined4 *)(uVar4 + 4),0xffffffff);
    if (iVar3 == 0) break;
    uVar4 = uVar4 + 0xc;
  }
  return uVar4;
}

