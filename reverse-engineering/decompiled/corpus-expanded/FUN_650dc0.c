/* Ghidra pseudocode, not original source.
 * ev_73d54611eb9c539f60191f4cc2589103d1525e4e98579cab30a489e0835b3840
 * Entry: 0x650dc0; label: FUN_00650dc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00650dc0(int param_1)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = DAT_0292fda0;
  if (param_1 == 0) {
    return -1;
  }
  if (DAT_0292fda0 == 0) {
    return -1;
  }
  uVar3 = FUN_00650430(param_1);
  sVar1 = *(short *)(iVar2 + (uVar3 & 0xff) * 2);
  while( true ) {
    iVar2 = (int)sVar1;
    if (iVar2 == -1) {
      return -1;
    }
    iVar4 = FUN_004f8b80(param_1,*(undefined4 *)(iVar2 * 0x40 + DAT_02947b74),0x20);
    if (iVar4 == 0) break;
    sVar1 = *(short *)(iVar2 * 0x40 + 0x10 + DAT_02947b74);
  }
  return iVar2;
}

