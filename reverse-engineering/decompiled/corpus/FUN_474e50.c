/* Ghidra analysis pseudocode, not original source.
 * ev_ad9cc5423de1ab1dd38d346f275414df9adbe91527778a2cec40e67e5c2b6778
 * Entry: 0x474e50; label: FUN_00474e50
 */

void FUN_00474e50(int param_1)

{
  int *piVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  bVar3 = DAT_0086e4e2;
  bVar2 = 0;
  if (PTR_s_negotiations_007f9368 != (undefined *)0x0) {
    iVar6 = 0;
    iVar5 = 0;
    do {
      if (*(int *)((int)&DAT_007f939c + iVar6) != 0) {
        iVar4 = FUN_0055a1b0(*(undefined4 *)(param_1 + 0x2ac8),*(int *)((int)&DAT_007f939c + iVar6),
                             0,0);
        if (iVar4 == 0) {
          piVar1 = *(int **)((int)&DAT_007f939c + iVar6);
          if (bVar3 < *(byte *)(*piVar1 + 0x6c)) {
            FUN_0055a2b0(*(undefined4 *)(param_1 + 0x2ac8),piVar1,0,0);
            FUN_00474df0(bVar3);
          }
          else if ((*(byte *)(*piVar1 + 0x7a) & 1) == 0) {
            FUN_0055a250(*(undefined4 *)(param_1 + 0x2ac8),piVar1,1,0);
          }
        }
        iVar6 = FUN_0055a1b0(*(undefined4 *)(param_1 + 0x2ac8),
                             *(undefined4 *)((int)&DAT_007f939c + iVar6),0,0);
        if (iVar6 != 0) {
          DAT_0086e4e4 = DAT_0086e4e4 | '\x01' << (bVar2 & 0x1f);
        }
        bVar2 = bVar2 + 1;
      }
      iVar5 = iVar5 + 1;
      iVar6 = iVar5 * 0x3c;
    } while ((&PTR_s_negotiations_007f9368)[iVar5 * 0xf] != (undefined *)0x0);
  }
  return;
}

