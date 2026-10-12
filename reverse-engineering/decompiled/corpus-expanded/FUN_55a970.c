/* Ghidra pseudocode, not original source.
 * ev_8c943698e03161dcf7a1afd17c02789bd1a03bc5c571948a550cbb172219f06a
 * Entry: 0x55a970; label: FUN_0055a970
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0055a970(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  
  if ((param_1 != (int *)0x0) && (param_2 != 0)) {
    iVar4 = *param_1;
    param_1 = (int *)0x0;
    if (0 < *DAT_0093b268) {
      piVar6 = (int *)(iVar4 + 4);
      piVar5 = (int *)(DAT_0093b268[2] + 0x44);
      piVar3 = DAT_0093b268;
      do {
        if (*piVar5 != 0) {
          iVar4 = piVar6[2];
          iVar7 = 0;
          if (0 < *piVar6) {
            do {
              uVar1 = (*(code *)*piVar5)(iVar4);
              iVar2 = FUN_004f8b10(param_2,uVar1);
              if (iVar2 == 0) {
                return 0;
              }
              iVar7 = iVar7 + 1;
              iVar4 = iVar4 + 8;
              piVar3 = DAT_0093b268;
            } while (iVar7 < *piVar6);
          }
        }
        param_1 = (int *)((int)param_1 + 1);
        piVar5 = piVar5 + 0x27;
        piVar6 = piVar6 + 5;
      } while ((int)param_1 < *piVar3);
    }
  }
  return 1;
}

