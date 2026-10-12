/* Ghidra pseudocode, not original source.
 * ev_b07f36f396508f1f1c6b60e4fa7f99c8658995938fec5aefc7408e7826e0de77
 * Entry: 0x65d7d0; label: FUN_0065d7d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065d7d0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  
  uVar3 = _DAT_00810a28;
  iVar2 = param_1 * 0x44;
  *(undefined4 *)(&DAT_02947d9c + iVar2) = *param_2;
  *(undefined4 *)(&DAT_02947da0 + iVar2) = param_2[1];
  uVar1 = param_2[2];
  (&DAT_02947da8)[param_1 * 0x11] = uVar3;
  uVar3 = _DAT_00810a2c;
  *(undefined4 *)(&DAT_02947da4 + iVar2) = uVar1;
  uVar4 = (undefined2)DAT_0296297c;
  (&DAT_02947dac)[param_1 * 0x11] = uVar3;
  (&DAT_02947db0)[param_1 * 0x22] = uVar4;
  (&DAT_02947db2)[param_1 * 0x22] = DAT_02962980;
  (&DAT_02947db5)[iVar2] = DAT_00810a30;
  (&DAT_02947db6)[iVar2] = DAT_00810a34;
  (&DAT_02947db8)[param_1 * 0x11] = DAT_02920d80;
  (&DAT_02947dbc)[param_1 * 0x11] = DAT_0292fdb4;
  FUN_0065d630();
  return;
}

