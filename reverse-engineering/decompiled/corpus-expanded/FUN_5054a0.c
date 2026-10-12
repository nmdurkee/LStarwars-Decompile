/* Ghidra pseudocode, not original source.
 * ev_4955bd160544e7c7d97f773b8b388f36e51fe983a9fd069cd072b2ef5022de80
 * Entry: 0x5054a0; label: FUN_005054a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_005054a0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar4 = 0;
  if (0 < *(int *)(iVar1 + 8)) {
    iVar5 = 0;
    do {
      iVar2 = FUN_004f8b10(*(undefined4 *)(iVar5 + *(int *)(iVar1 + 0xc)),param_2);
      if (iVar2 == 0) {
        iVar2 = *(int *)(iVar1 + 0xc) + iVar5;
        if ((*(int *)(*(int *)(iVar1 + 0xc) + 4 + iVar5) == 1) &&
           (((*(byte *)(iVar2 + 0xc) & 8) == 0 || (param_5 != 0)))) {
          if (*(short *)(iVar2 + 0x2e) < 0) {
            iVar2 = FUN_00505200(iVar2,param_3,param_4);
          }
          else {
            iVar3 = *(short *)(iVar2 + 0x2e) * 0x50 + *(int *)(*(int *)(param_1 + 0x10) + 0x20);
            if ((*(byte *)(iVar3 + 0x44) & 1) == 0) goto LAB_00505552;
            if (*(int *)(iVar3 + 0x48) == 0) {
              iVar2 = FUN_00504eb0(iVar2,iVar3,param_3,param_4);
            }
            else {
              iVar2 = FUN_00504eb0(iVar2,*(int *)(iVar3 + 0x48),param_3,param_4);
            }
          }
          if (iVar2 != 0) {
            return 1;
          }
        }
      }
LAB_00505552:
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x34;
    } while (iVar4 < *(int *)(iVar1 + 8));
  }
  return 0;
}

