/* Ghidra pseudocode, not original source.
 * ev_4005f8bc77e113ad185f3b0c9eec9d65d23a3485fd73b1b18a7c340409abf10a
 * Entry: 0x6be190; label: FUN_006be190
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006be190(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined1 local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_84;
  if (param_1[2] == 2) {
    uVar1 = FUN_005cfa50(param_2);
    (**(code **)(*param_1 + 0x14))(uVar1,0);
  }
  if (param_1[2] == 1) {
    (**(code **)(*param_1 + 0x14))(local_84,0x80);
    FUN_005cf5b0(0,param_2,local_84,0);
    uVar3 = 0;
    if (0 < DAT_02973e98) {
      puVar4 = &DAT_02973f3c;
      do {
        if (uVar3 < 10) {
          uVar1 = *puVar4;
        }
        else {
          uVar1 = 0;
        }
        iVar2 = FUN_005cf5b0(uVar1,param_2,local_84,0);
        if (iVar2 != 0) break;
        uVar3 = uVar3 + 1;
        puVar4 = puVar4 + 0x2a;
      } while ((int)uVar3 < DAT_02973e98);
    }
  }
  __security_check_cookie(local_4 ^ (uint)local_84);
  return;
}

