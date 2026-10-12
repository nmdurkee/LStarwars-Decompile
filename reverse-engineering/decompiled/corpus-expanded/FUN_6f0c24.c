/* Ghidra pseudocode, not original source.
 * ev_97f9900fcd0ba7492838edfd98b0150dba956191b40272664bd26bb1f92bea67
 * Entry: 0x6f0c24; label: FUN_006f0c24
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006f0c24(int param_1,undefined4 param_2)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  
  iVar4 = FUN_006f0395();
  uVar6 = 0;
  if (iVar4 != 0) {
    piVar1 = *(int **)(iVar4 + 0x5c);
    piVar5 = piVar1;
    do {
      if (*piVar5 == param_1) break;
      piVar5 = piVar5 + 3;
    } while (piVar5 < piVar1 + DAT_00829bfc * 3);
    if ((piVar1 + DAT_00829bfc * 3 <= piVar5) || (*piVar5 != param_1)) {
      piVar5 = (int *)0x0;
    }
    if ((piVar5 == (int *)0x0) || (pcVar2 = (code *)piVar5[2], pcVar2 == (code *)0x0)) {
      uVar6 = 0;
    }
    else if (pcVar2 == (code *)0x5) {
      piVar5[2] = 0;
      uVar6 = 1;
    }
    else {
      if (pcVar2 != (code *)0x1) {
        uVar6 = *(undefined4 *)(iVar4 + 0x60);
        *(undefined4 *)(iVar4 + 0x60) = param_2;
        if (piVar5[1] == 8) {
          if (DAT_00829bf0 < DAT_00829bf4 + DAT_00829bf0) {
            iVar7 = DAT_00829bf0 * 0xc;
            iVar8 = DAT_00829bf0;
            do {
              *(undefined4 *)(iVar7 + 8 + *(int *)(iVar4 + 0x5c)) = 0;
              iVar8 = iVar8 + 1;
              iVar7 = iVar7 + 0xc;
            } while (iVar8 < DAT_00829bf4 + DAT_00829bf0);
          }
          iVar8 = *piVar5;
          uVar3 = *(undefined4 *)(iVar4 + 100);
          if (iVar8 == -0x3fffff72) {
            *(undefined4 *)(iVar4 + 100) = 0x83;
          }
          else if (iVar8 == -0x3fffff70) {
            *(undefined4 *)(iVar4 + 100) = 0x81;
          }
          else if (iVar8 == -0x3fffff6f) {
            *(undefined4 *)(iVar4 + 100) = 0x84;
          }
          else if (iVar8 == -0x3fffff6d) {
            *(undefined4 *)(iVar4 + 100) = 0x85;
          }
          else if (iVar8 == -0x3fffff73) {
            *(undefined4 *)(iVar4 + 100) = 0x82;
          }
          else if (iVar8 == -0x3fffff71) {
            *(undefined4 *)(iVar4 + 100) = 0x86;
          }
          else if (iVar8 == -0x3fffff6e) {
            *(undefined4 *)(iVar4 + 100) = 0x8a;
          }
          (*pcVar2)(8,*(undefined4 *)(iVar4 + 100));
          *(undefined4 *)(iVar4 + 100) = uVar3;
        }
        else {
          piVar5[2] = 0;
          (*pcVar2)(piVar5[1]);
        }
        *(undefined4 *)(iVar4 + 0x60) = uVar6;
      }
      uVar6 = 0xffffffff;
    }
  }
  return uVar6;
}

