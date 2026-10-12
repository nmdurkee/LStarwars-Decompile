/* Ghidra pseudocode, not original source.
 * ev_6293e9c45219377b80e3d0963b70152e043cc5400ac7177165af43f16814c89d
 * Entry: 0x4424c0; label: FUN_004424c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004424c0(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_2 == 0) {
    return -1;
  }
  iVar2 = 0;
  puVar3 = (undefined4 *)(param_3 + 0x18);
  do {
    iVar1 = FUN_004f8b10(*puVar3,param_2);
    if (iVar1 == 0) {
      return iVar2;
    }
    iVar2 = iVar2 + 1;
    puVar3 = puVar3 + 2;
  } while (iVar2 < 4);
  iVar2 = FUN_004f29a0(param_2);
  return iVar2;
}

