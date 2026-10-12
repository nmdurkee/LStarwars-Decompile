/* Ghidra pseudocode, not original source.
 * ev_4aacc4015277efc7c796a4684ec1a2293d4b851b48a9fd84999ecda53bd8e95c
 * Entry: 0x502020; label: FUN_00502020
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00502020(int param_1)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_c;
  undefined4 local_8;
  int local_4;
  
  piVar1 = *(int **)(in_EAX + 0x14);
  if ((param_1 != 0) && (iVar3 = 0, (short)piVar1[1] != 0)) {
    iVar4 = 0;
    do {
      iVar5 = *piVar1 + iVar4;
      if ((*(byte *)(iVar5 + 0x58) & 4) == 0) {
        iVar2 = FUN_005cf5b0(param_1,&local_c,*(undefined4 *)(iVar5 + 0x40),1);
        if (iVar2 == 0) {
          FUN_004fff10(*(undefined4 *)(iVar5 + 0x40));
        }
        else {
          *(byte *)(iVar5 + 0x58) = *(byte *)(iVar5 + 0x58) | 4;
          *(undefined4 *)(iVar5 + 0x44) = local_c;
          if (local_4 == 0) {
            *(undefined4 *)(iVar5 + 0x48) = local_8;
          }
          else {
            *(int *)(iVar5 + 0x48) = local_4;
          }
        }
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x5c;
    } while (iVar3 < (int)(uint)*(ushort *)(piVar1 + 1));
  }
  return;
}

