/* Ghidra pseudocode, not original source.
 * ev_77c3e64cbf166009276f17c020938a120e86ba2ebeb248b147f617680a486917
 * Entry: 0x607590; label: FUN_00607590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00607590(int param_1,int param_2)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_40;
  undefined1 local_3c [16];
  undefined4 local_2c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_8;
  
  if ((param_2 != 0) && (*(int *)(*(int *)(param_1 + 8) + 0x20) != *(int *)(param_2 + 0x20))) {
    if (*(short *)(*(int *)(param_1 + 8) + 0x24) != *(short *)(param_2 + 0x24)) {
      if (*(int *)(param_2 + 0x34) == 0) {
        uVar2 = FUN_005fcdf0(param_2);
        *(undefined4 *)(param_2 + 0x34) = uVar2;
      }
      FUN_006034b0(param_1,0x94,*(undefined4 *)(param_2 + 0x34));
      *(undefined2 *)(*(int *)(param_1 + 8) + 0x24) = *(undefined2 *)(param_2 + 0x24);
    }
    if (*(short *)(*(int *)(param_1 + 8) + 0x2c) != *(short *)(param_2 + 0x2c)) {
      if (*(int *)(param_2 + 0x110) == 0) {
        _memset(local_3c,0,0x3c);
        local_40 = *(undefined4 *)(param_2 + 0x154);
        local_2c = *(undefined4 *)(param_2 + 0x158);
        local_18 = *(undefined4 *)(param_2 + 0x15c);
        local_14 = *(undefined4 *)(param_2 + 0x160);
        local_8 = *(undefined4 *)(param_2 + 0x164);
        *DAT_009736e0 = *DAT_009736e0 + 0xf & 0xfffffff0;
        puVar1 = DAT_009736e0;
        *(uint *)(param_2 + 0x110) = *DAT_009736e0;
        *(int *)*puVar1 =
             (*(short *)(param_2 + 0x2c) + 5) * (*(int *)(param_2 + 0x20) + 0xd) + DAT_0297dc00;
        *puVar1 = *puVar1 + 4;
        puVar4 = (undefined4 *)(param_2 + 0x114);
        puVar5 = (undefined4 *)*puVar1;
        for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
        *puVar1 = *puVar1 + 0x40;
        puVar4 = &local_40;
        puVar5 = (undefined4 *)*puVar1;
        for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
        *puVar1 = *puVar1 + 0x40;
        puVar4 = (undefined4 *)*puVar1;
        uVar2 = *(undefined4 *)(param_2 + 0x184);
        *puVar1 = (uint)(puVar4 + 1);
        *puVar4 = uVar2;
        uVar2 = *(undefined4 *)(param_2 + 0x188);
        *puVar1 = (uint)(puVar4 + 2);
        puVar4[1] = uVar2;
        uVar2 = *(undefined4 *)(param_2 + 0x18c);
        *puVar1 = (uint)(puVar4 + 3);
        puVar4[2] = uVar2;
        puVar4[3] = *(undefined4 *)(param_2 + 400);
        *puVar1 = (uint)(puVar4 + 4);
      }
      FUN_006034b0(param_1,0x9a,*(undefined4 *)(param_2 + 0x110));
      *(undefined2 *)(*(int *)(param_1 + 8) + 0x2c) = *(undefined2 *)(param_2 + 0x2c);
    }
    if (*(short *)(*(int *)(param_1 + 8) + 0x2e) != *(short *)(param_2 + 0x2e)) {
      if (*(int *)(param_2 + 0x168) == 0) {
        uVar2 = FUN_005fcf60(param_2);
        *(undefined4 *)(param_2 + 0x168) = uVar2;
      }
      FUN_006034b0(param_1,0xa6,*(undefined4 *)(param_2 + 0x168));
      *(undefined2 *)(*(int *)(param_1 + 8) + 0x2e) = *(undefined2 *)(param_2 + 0x2e);
    }
    if (*(short *)(*(int *)(param_1 + 8) + 0x1e) != *(short *)(param_2 + 0x1e)) {
      if (*(int *)(param_2 + 0x180) == 0) {
        uVar2 = FUN_005fcef0(param_2);
        *(undefined4 *)(param_2 + 0x180) = uVar2;
      }
      FUN_006034b0(param_1,0xa5,*(undefined4 *)(param_2 + 0x180));
      *(undefined2 *)(*(int *)(param_1 + 8) + 0x1e) = *(undefined2 *)(param_2 + 0x1e);
    }
    if (*(short *)(*(int *)(param_1 + 8) + 0x32) != *(short *)(param_2 + 0x32)) {
      if (*(int *)(param_2 + 0x198) == 0) {
        uVar2 = FUN_005fcf30(param_2);
        *(undefined4 *)(param_2 + 0x198) = uVar2;
      }
      FUN_006034b0(param_1,0xab,*(undefined4 *)(param_2 + 0x198));
      *(undefined2 *)(*(int *)(param_1 + 8) + 0x32) = *(undefined2 *)(param_2 + 0x32);
    }
    if (*(short *)(*(int *)(param_1 + 8) + 0x30) != *(short *)(param_2 + 0x30)) {
      iVar3 = FUN_005fcfd0(param_2);
      if (iVar3 != 0) {
        FUN_006034b0(param_1,0xa9,iVar3);
      }
      *(undefined2 *)(*(int *)(param_1 + 8) + 0x30) = *(undefined2 *)(param_2 + 0x30);
    }
    *(undefined4 *)(*(int *)(param_1 + 8) + 0x20) = *(undefined4 *)(param_2 + 0x20);
  }
  return;
}

