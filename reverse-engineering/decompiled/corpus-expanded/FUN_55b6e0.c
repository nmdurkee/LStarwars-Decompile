/* Ghidra pseudocode, not original source.
 * ev_8c943698e03161dcf7a1afd17c02789bd1a03bc5c571948a550cbb172219f06a
 * Entry: 0x55b6e0; label: FUN_0055b6e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055b6e0(short *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  uint *puVar1;
  short *psVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 *local_108;
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_108;
  local_108 = param_4;
  if ((param_1 != (short *)0x0) && (DAT_0093b270 != 0)) {
    sVar3 = *param_1;
    iVar6 = DAT_0093b270;
    while (iVar4 = (int)sVar3, iVar4 != -1) {
      if (((*(int *)(iVar6 + iVar4 * 4) == 0) && (param_1[1] != 0)) &&
         (iVar7 = (int)*(short *)(iVar4 * 0x4c + 0x42 + DAT_0093b274), iVar7 != -1)) {
        FUN_004f1f10(local_104,s_stuff_icons__00802928);
        uVar5 = FUN_0057a360(iVar7);
        FUN_004f1e80(local_104,uVar5);
        FUN_004f1e80(local_104,&DAT_0075a1fc);
        iVar7 = FUN_005ef7f0(param_3,*local_108,local_104);
        iVar6 = DAT_0093b270;
        *(int *)(DAT_0093b270 + iVar4 * 4) = iVar7;
        if ((iVar7 != 0) && (*(int *)(iVar7 + 0x110) != 0)) {
          puVar1 = (uint *)(*(int *)(iVar7 + 0x110) + 0x74);
          *puVar1 = *puVar1 | 0x10;
        }
      }
      psVar2 = param_1 + 2;
      param_1 = param_1 + 2;
      sVar3 = *psVar2;
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_108);
  return;
}

