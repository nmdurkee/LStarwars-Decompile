/* Ghidra analysis pseudocode, not original source.
 * ev_11d21a68175a6094cc049e5bf26b7ff6a5a52d03a1d985acdd25f24f4e0bcb10
 * Entry: 0x611e00; label: FUN_00611e00
 */

void FUN_00611e00(ushort param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 ushort param_5)

{
  int iVar1;
  undefined4 uVar2;
  ushort *in_ECX;
  
  *(undefined4 *)(in_ECX + 6) = param_2;
  *in_ECX = *in_ECX | param_5;
  in_ECX[1] = param_1;
  *(undefined4 *)(in_ECX + 8) = param_3;
  *(undefined4 *)(in_ECX + 4) = param_4;
  iVar1 = FUN_006be780(param_3);
  if (0 < *(int *)(&DAT_02867f1c + iVar1 * 4)) {
    uVar2 = FUN_00633440(*(int *)(&DAT_02867f1c + iVar1 * 4),1);
    *(undefined4 *)(in_ECX + 10) = uVar2;
  }
  return;
}

