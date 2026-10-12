/* Ghidra pseudocode, not original source.
 * ev_57e4595202f6848139a561b6e4253d561eb3ad03e2f9632ed29ba9ff4f0bafc7
 * Entry: 0x59e4d0; label: FUN_0059e4d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059e4d0(int param_1)

{
  int *piVar1;
  byte *pbVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  char *pcVar8;
  byte *pbVar9;
  
  DAT_0095642c = 0;
  DAT_00956430 = 0;
  DAT_00956340 = 1;
  FUN_004f10e0(param_1,&PTR_s_Parent_008055b8);
  iVar4 = FUN_004fc5b0(param_1);
  while (iVar4 != 0) {
    FUN_004f7fb0(param_1);
    iVar4 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_0075ff74);
    if (iVar4 == 0) break;
    FUN_004fa020(param_1);
    iVar4 = FUN_004fc5b0(param_1);
  }
  FUN_004f11e0(param_1);
  iVar4 = DAT_0095642c;
  uVar6 = DAT_0095641c;
  if (DAT_00956420 != 0) {
    if (DAT_00956428 == (byte *)0x0) {
      DAT_00956424 = DAT_00956424 + -1;
      DAT_00956428 = (byte *)0x20;
      return;
    }
    pbVar9 = DAT_00956428;
    if (DAT_0095642c != 0) {
      *DAT_00956428 = (byte)DAT_0095642c;
      uVar5 = FUN_00559610(DAT_00956418,uVar6,iVar4 * 4);
      pbVar2 = DAT_00956428;
      uVar6 = DAT_0095641c;
      *(undefined4 *)(DAT_00956428 + 0x10) = uVar5;
      uVar6 = FUN_00559610(DAT_00956418,uVar6,DAT_0095642c);
      pbVar9 = DAT_00956428;
      *(undefined4 *)(pbVar2 + 0x18) = uVar6;
      iVar4 = DAT_00956420;
      iVar7 = 0;
      if (*pbVar9 != 0) {
        do {
          *(int *)(*(int *)(pbVar9 + 0x10) + iVar7 * 4) =
               (&DAT_009563d0)[iVar7] * 0x20 + *(int *)(iVar4 + 8);
          *(undefined1 *)(iVar7 + *(int *)(pbVar2 + 0x18)) = (&DAT_009562e8)[iVar7];
          iVar7 = iVar7 + 1;
        } while (iVar7 < (int)(uint)*pbVar9);
      }
    }
    iVar4 = DAT_00956430;
    uVar6 = DAT_00956418;
    if (DAT_00956430 != 0) {
      pbVar9[2] = (byte)DAT_00956430;
      uVar6 = FUN_00559610(uVar6,DAT_0095641c,iVar4 * 4);
      pbVar2 = DAT_00956428;
      *(undefined4 *)(pbVar9 + 0x14) = uVar6;
      iVar4 = DAT_00956420;
      iVar7 = 0;
      if (pbVar2[2] != 0) {
        do {
          piVar1 = &DAT_00956350 + iVar7;
          iVar7 = iVar7 + 1;
          *(int *)(*(int *)(pbVar9 + 0x14) + -4 + iVar7 * 4) = *piVar1 * 0x20 + *(int *)(iVar4 + 8);
        } while (iVar7 < (int)(uint)pbVar2[2]);
      }
    }
    pcVar3 = &DAT_00956320;
    do {
      pcVar8 = pcVar3;
      pcVar3 = pcVar8 + 1;
    } while (*pcVar8 != '\0');
    uVar6 = FUN_00559610(DAT_00956418,DAT_0095641c,pcVar8 + -0x95631f);
    *(undefined4 *)(DAT_00956428 + 0x1c) = uVar6;
    FUN_004f1f10(uVar6,&DAT_00956320);
  }
  DAT_00956424 = DAT_00956424 + -1;
  DAT_00956428 = DAT_00956428 + 0x20;
  return;
}

