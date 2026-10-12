/* Ghidra analysis pseudocode, not original source.
 * ev_64710b70227263f531e000337bf3c7b84d0ba3dbee751b1080463e073dfde27a
 * Entry: 0x6e2880; label: FUN_006e2880
 */

void FUN_006e2880(int param_1,int param_2)

{
  ushort uVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x638) == 0) && (1 < DAT_02974d1c)) {
    uVar1 = *(ushort *)(in_ECX + 0xf8);
  }
  else {
    uVar1 = 1;
  }
  if ((param_1 <= (int)(uVar1 - 1)) && (*(int *)(in_ECX + 0x6f0 + param_1 * 4) != param_2)) {
    *(int *)(in_ECX + 0x6f0 + param_1 * 4) = param_2;
    (**(code **)(**(int **)(in_ECX + 4) + 0x94))(*(int **)(in_ECX + 4),param_1,param_2);
  }
  return;
}

