/* Ghidra pseudocode, not original source.
 * ev_4aa7baba24777c7cef62b6758f8d176321ddee5c4eaac4ea92e033f295beb802
 * Entry: 0x44f930; label: FUN_0044f930
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0044f930(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 local_4;
  
  iVar6 = 0;
  iVar5 = 0;
  local_4 = 0;
  bVar1 = false;
  if (param_6 != 0) {
    if (((param_3 != 0) && (piVar3 = *(int **)(param_3 + 0xd0), piVar3 != (int *)0x0)) &&
       (*piVar3 != 0)) {
      iVar5 = *piVar3;
    }
    if (0 < param_5) {
      do {
        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"character=");
        if (iVar2 == 0) {
          iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"tag_to=");
          if (iVar2 == 0) {
            iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar6 * 4),"FALSE");
            if (iVar2 == 0) {
              bVar1 = true;
            }
          }
          else if ((DAT_00923904 == (code *)0x0) ||
                  (puVar4 = (undefined4 *)(*DAT_00923904)(param_1,iVar2 + 7),
                  puVar4 == (undefined4 *)0x0)) {
            local_4 = 0;
          }
          else {
            local_4 = *puVar4;
          }
        }
        else if ((DAT_00923904 == (code *)0x0) ||
                (piVar3 = (int *)(*DAT_00923904)(param_1,iVar2 + 10), piVar3 == (int *)0x0)) {
          iVar5 = 0;
        }
        else {
          iVar5 = *piVar3;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < param_5);
    }
    if (iVar5 != 0) {
      if ((bVar1) && ((*(byte *)(iVar5 + 0x1fc) & 0x80) != 0)) {
        if (*(int *)(iVar5 + 0xcd0) == 0) {
          iVar6 = FUN_00487ca0(iVar5,local_4,0);
          if (iVar6 == 0) {
            bVar1 = false;
          }
        }
        else {
          FUN_004882d0(iVar5);
        }
        FUN_0055e410();
      }
      *(byte *)(iVar5 + 0x7c5) =
           *(byte *)(iVar5 + 0x7c5) ^ (bVar1 * '\x02' ^ *(byte *)(iVar5 + 0x7c5)) & 2;
    }
  }
  return 1;
}

