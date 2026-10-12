/* Ghidra pseudocode, not original source.
 * ev_b07f36f396508f1f1c6b60e4fa7f99c8658995938fec5aefc7408e7826e0de77
 * Entry: 0x65d630; label: FUN_0065d630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065d630(int param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c [12];
  
  iVar4 = param_1 * 0x44;
  if ((&DAT_02947d98)[param_1 * 0x11] != -1) {
    FUN_00543fd0((&DAT_02947d98)[param_1 * 0x11]);
    (&DAT_02947d98)[param_1 * 0x11] = 0xffffffff;
  }
  local_30 = (&DAT_02947da8)[param_1 * 0x11];
  local_2c = 0;
  local_28 = 0;
  FUN_005b3690(&local_30,&local_30,(int)(short)(&DAT_02947db0)[param_1 * 0x22]);
  FUN_005b3620(&local_30,&local_30,(int)(short)(&DAT_02947db2)[param_1 * 0x22]);
  FUN_005b37d0(local_c,&DAT_02947d9c + iVar4,&local_30);
  bVar1 = (&DAT_02947dda)[iVar4];
  bVar2 = (&DAT_02947dd9)[iVar4];
  bVar3 = (&DAT_02947dd8)[iVar4];
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  if ((&DAT_02947db8)[param_1 * 0x11] != -1) {
    FUN_005da860(&local_18,DAT_02962114,(&DAT_02947db8)[param_1 * 0x11]);
  }
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  if ((&DAT_02947dbc)[param_1 * 0x11] != -1) {
    FUN_005da860(&local_24,DAT_02962114,(&DAT_02947dbc)[param_1 * 0x11]);
  }
  uVar5 = FUN_00544070(param_2,&local_18,&local_24,&DAT_02947d9c + iVar4,local_c,
                       (&DAT_02947dd4)[param_1 * 0x11],(&DAT_02947db2)[param_1 * 0x22],
                       (&DAT_02947dc0)[param_1 * 0x11],(&DAT_02947dc4)[param_1 * 0x11],
                       (&DAT_02947dc8)[param_1 * 0x11],(&DAT_02947dcc)[param_1 * 0x11],
                       (int)(char)(&DAT_02947db5)[iVar4],(&DAT_02947dac)[param_1 * 0x11],
                       (&DAT_02947dd0)[param_1 * 0x11],(int)(char)(&DAT_02947db6)[iVar4],
                       ((bVar1 - 0x8000) * 0x100 + (uint)bVar2) * 0x100 + (uint)bVar3);
  (&DAT_02947d98)[param_1 * 0x11] = uVar5;
  return;
}

