/* Ghidra pseudocode, not original source.
 * ev_129ae85c041da73e18ad3e5240adb251de7047e60e981c2b1daa2599efa26a06
 * Entry: 0x6893e0; label: FUN_006893e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006893e0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  undefined4 local_20;
  int local_1c;
  char local_18 [20];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_20;
  local_20 = param_2;
  iVar7 = 0;
  do {
    if ((&DAT_029211c8)[iVar7] == 0) {
      if (iVar7 != -1) {
        FUN_006211c0(1);
        iVar4 = FUN_00621270(param_1,0);
        if (iVar4 != 0) {
          iVar4 = FUN_006217e0();
          if (1 < iVar4) {
            FUN_006213e0();
            __security_check_cookie(local_4 ^ (uint)&local_20);
            return;
          }
          iVar4 = FUN_006217e0();
          if (0x40 < DAT_02962974 + iVar4) {
            iVar4 = 0x40 - DAT_02962974;
          }
          iVar8 = 0;
          if (0 < iVar4) {
            do {
              local_1c = iVar4;
              pcVar5 = &DAT_02947db4 + iVar8 * 0x44;
              cVar1 = (&DAT_02947db4)[iVar8 * 0x44];
              while (cVar1 != -1) {
                if (0x2948eb3 < (int)pcVar5) goto LAB_00689617;
                pcVar5 = pcVar5 + 0x44;
                iVar8 = iVar8 + 1;
                cVar1 = *pcVar5;
              }
              if (iVar8 < 0x40) {
                iVar4 = iVar8 * 0x44;
                (&DAT_02947d98)[iVar8 * 0x11] = 0xffffffff;
                FUN_00621900(&DAT_02947d9c + iVar4);
                fVar9 = (float10)FUN_006217a0();
                (&DAT_02947da8)[iVar8 * 0x11] = (float)fVar9;
                fVar9 = (float10)FUN_006217a0();
                (&DAT_02947dac)[iVar8 * 0x11] = (float)fVar9;
                uVar3 = FUN_00621860();
                (&DAT_02947db0)[iVar8 * 0x22] = uVar3;
                uVar3 = FUN_00621860();
                (&DAT_02947db2)[iVar8 * 0x22] = uVar3;
                (&DAT_02947db4)[iVar4] = (char)iVar7;
                uVar2 = FUN_006218c0();
                (&DAT_02947db5)[iVar4] = uVar2;
                uVar2 = FUN_006218c0();
                (&DAT_02947db6)[iVar4] = uVar2;
                FUN_006216f0(local_18,0x14);
                if (local_18[0] == '\0') {
                  (&DAT_02947db8)[iVar8 * 0x11] = 0xffffffff;
                }
                else {
                  uVar6 = FUN_0065c620(local_18,local_20);
                  (&DAT_02947db8)[iVar8 * 0x11] = uVar6;
                }
                FUN_006216f0(local_18,0x14);
                if (local_18[0] == '\0') {
                  (&DAT_02947dbc)[iVar8 * 0x11] = 0xffffffff;
                }
                else {
                  uVar6 = FUN_0065c620(local_18,local_20);
                  (&DAT_02947dbc)[iVar8 * 0x11] = uVar6;
                }
                fVar9 = (float10)FUN_006217a0();
                (&DAT_02947dc0)[iVar8 * 0x11] = (float)fVar9;
                fVar9 = (float10)FUN_006217a0();
                (&DAT_02947dc4)[iVar8 * 0x11] = (float)fVar9;
                fVar9 = (float10)FUN_006217a0();
                (&DAT_02947dc8)[iVar8 * 0x11] = (float)fVar9;
                fVar9 = (float10)FUN_006217a0();
                (&DAT_02947dcc)[iVar8 * 0x11] = (float)fVar9;
                fVar9 = (float10)FUN_006217a0();
                (&DAT_02947dd0)[iVar8 * 0x11] = (float)fVar9;
                fVar9 = (float10)FUN_006217a0();
                (&DAT_02947dd4)[iVar8 * 0x11] = (float)fVar9;
                uVar2 = FUN_006218c0();
                (&DAT_02947dd8)[iVar4] = uVar2;
                uVar2 = FUN_006218c0();
                (&DAT_02947dd9)[iVar4] = uVar2;
                uVar2 = FUN_006218c0();
                (&DAT_02947dda)[iVar4] = uVar2;
                uVar2 = FUN_006218c0();
                DAT_02962974 = DAT_02962974 + 1;
                (&DAT_02947ddb)[iVar4] = uVar2;
              }
LAB_00689617:
              local_1c = local_1c + -1;
              iVar4 = local_1c;
            } while (local_1c != 0);
          }
          FUN_006213e0();
          DAT_02947c14 = 0xffffffff;
          FUN_0065d540(0x3f800000);
          (&DAT_029211c8)[iVar7] = 1;
          *(undefined4 *)(&DAT_0292fc3c + iVar7 * 4) = local_20;
          __security_check_cookie(local_4 ^ (uint)&local_20);
          return;
        }
      }
      break;
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 8);
  __security_check_cookie(local_4 ^ (uint)&local_20);
  return;
}

