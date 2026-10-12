/* Ghidra pseudocode, not original source.
 * ev_2606baf984ee455df312fc83a5be5e2bd228e340f9dbc5529ae9524aab57b603
 * Entry: 0x47ba10; label: FUN_0047ba10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047ba10(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined4 *puVar3;
  short *psVar4;
  undefined2 *puVar5;
  
  uVar1 = *(ushort *)(param_1 * 0x9c + 0x7a + DAT_00951354);
  psVar4 = DAT_00855ed0;
  if ((uVar1 & 1) == 0) {
    puVar3 = &DAT_00855ea4;
LAB_0047ba3e:
    if (((short **)puVar3 != &DAT_00855ed0) &&
       (psVar4 = DAT_00855f24, (short **)puVar3 != &DAT_00855f24)) {
      param_3 = -1;
      param_2 = -1;
      goto LAB_0047ba78;
    }
  }
  else if ((uVar1 & 4) != 0) {
    puVar3 = &DAT_00855f24;
    goto LAB_0047ba3e;
  }
  if (param_2 == -1) {
    param_2 = (int)*psVar4;
  }
  if (param_3 == -1) {
    param_3 = (int)psVar4[0xe];
  }
LAB_0047ba78:
  FUN_00476840(param_2);
  if ((param_2 == -1) || (param_3 == -1)) {
    if (DAT_0093d7f0 == 0) {
      DAT_0087b6c4 = 0xffff;
    }
    else {
      DAT_0087b6c4 = *(undefined2 *)(DAT_0093d7f0 + 0x1064);
    }
    if (DAT_0093d7f4 == 0) {
      DAT_0087b6c6 = 0xffff;
    }
    else {
      DAT_0087b6c6 = *(undefined2 *)(DAT_0093d7f4 + 0x1064);
    }
  }
  else {
    DAT_0087b6c4 = (undefined2)param_2;
    DAT_0087b6c6 = (undefined2)param_3;
  }
  DAT_00879564 = 0;
  DAT_00879540 = 0;
  DAT_0087955c = 0;
  DAT_00879560 = 0;
  _DAT_00879504 = 0x3f800000;
  puVar5 = &DAT_00879b58;
  _DAT_0087b58c = 0;
  _DAT_0087b584 = 0;
  _DAT_0087b5b8 = 0;
  _DAT_0087b570 = 0;
  _DAT_0087b590 = 0;
  _DAT_0087b588 = 0;
  _DAT_0087b5bc = 0;
  _DAT_0087b574 = 0;
  puVar3 = &DAT_00879b60;
  do {
    uVar2 = FUN_0054fa60();
    *puVar5 = uVar2;
    *puVar3 = 0;
    puVar5 = puVar5 + 1;
    puVar3 = puVar3 + 1;
  } while ((int)puVar5 < 0x879b60);
  DAT_00879afc = param_1;
  return;
}

