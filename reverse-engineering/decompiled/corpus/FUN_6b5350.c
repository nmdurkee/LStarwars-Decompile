/* Ghidra analysis pseudocode, not original source.
 * ev_7c9627a116e74c10f7e1ba5a6ebe852fd25b4abb6a97a0a4eb0abdf2e857683f
 * Entry: 0x6b5350; label: FUN_006b5350
 */

void FUN_006b5350(int param_1,int param_2,int param_3)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  uVar8 = in_EAX - in_ECX;
  iVar4 = param_2 - param_1;
  iVar2 = (int)uVar8 / iVar4;
  iVar5 = iVar2 + -1;
  if (-1 < (int)uVar8) {
    iVar5 = iVar2 + 1;
  }
  uVar6 = iVar2 * iVar4 >> 0x1f;
  iVar3 = param_1 + 1;
  *(int *)(param_3 + param_1 * 4) = in_ECX;
  if (iVar3 < param_2) {
    iVar7 = 0;
    do {
      iVar7 = iVar7 + (((uVar8 ^ (int)uVar8 >> 0x1f) - ((int)uVar8 >> 0x1f)) -
                      ((iVar2 * iVar4 ^ uVar6) - uVar6));
      iVar1 = iVar2;
      if (iVar4 <= iVar7) {
        iVar7 = iVar7 - iVar4;
        iVar1 = iVar5;
      }
      in_ECX = in_ECX + iVar1;
      *(int *)(param_3 + iVar3 * 4) = in_ECX;
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_2);
  }
  return;
}

