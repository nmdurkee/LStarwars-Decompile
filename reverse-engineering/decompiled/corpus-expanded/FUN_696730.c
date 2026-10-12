/* Ghidra pseudocode, not original source.
 * ev_45200ba16e8ef520c819c849d12b8874968ca721432c6a61fa3b24bce95adf30
 * Entry: 0x696730; label: FUN_00696730
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00696730(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  
  iVar2 = in_ECX[1];
  if (0x200 < iVar2) {
    iVar2 = FUN_00693b60();
  }
  in_ECX[1] = iVar2 + 1;
  in_ECX[7] = *in_ECX + iVar2 * 0x24;
  *(int *)(in_ECX[7] + 4) = in_ECX[2] + in_ECX[3] * 0x3c;
  *(undefined4 *)(in_ECX[7] + 8) = 0;
  FUN_004f7fb0(param_1);
  uVar1 = *(undefined4 *)(param_1 + 0x510);
  iVar2 = FUN_006946b0(uVar1);
  if (iVar2 == 0) {
    iVar2 = in_ECX[0x4b];
    iVar3 = FUN_004f1ff0(uVar1);
    in_ECX[0x4b] = in_ECX[0x4b] + iVar3 + 1;
    FUN_004f1f10(iVar2,uVar1);
    *(int *)in_ECX[7] = iVar2;
    return;
  }
  *(int *)in_ECX[7] = iVar2;
  return;
}

