/* Ghidra pseudocode, not original source.
 * ev_fbc0fd73cf89a7f733f4465e4ab1049333b8e7c593c45a6546f4f82b49062809
 * Entry: 0x5eeb30; label: FUN_005eeb30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005eeb30(int param_1)

{
  uint *puVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  bool bVar9;
  
  FUN_00600bd0(param_1);
  puVar6 = DAT_00973990;
  if (DAT_00973990 == (undefined *)0x0) {
    puVar6 = &DAT_00971894;
  }
  if (DAT_0080ba58 == 0) {
    FUN_00600c60(param_1);
  }
  else if (((*(int *)(param_1 + 0x6c) != 0) && (*(int *)(param_1 + 0x74) != 0)) &&
          (*(int *)(param_1 + 0xf4) != 0)) {
    DAT_00963f98 = (undefined4 *)(param_1 + 0xdc);
    *DAT_00963f98 = 0;
    DAT_00963e00 = param_1 + 0x9c;
    FUN_00600cb0(param_1);
    fVar2 = DAT_00973730;
    _DAT_0097189c = DAT_00973720;
    _DAT_00971898 = DAT_0097371c;
    puVar7 = &DAT_009736e8;
    puVar8 = &DAT_0095fb78;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    DAT_0096e564 = &DAT_009736e8;
    _DAT_00971894 = DAT_00973718;
    DAT_00971abc = FUN_005d92b0(param_1,puVar6);
    bVar9 = DAT_00971abc == -1;
    *(int *)(param_1 + 0xe0) = (int)DAT_00971abc;
    if (bVar9) {
      return 0;
    }
    _DAT_00971860 = _DAT_0095fb98;
    _DAT_00963f78 = _DAT_0095fb98;
    _DAT_00971864 = _DAT_0095fb9c;
    _DAT_00963f7c = _DAT_0095fb9c;
    _DAT_00971868 = _DAT_0095fba0;
    _DAT_00963f80 = _DAT_0095fba0;
    _DAT_0097186c =
         -(_DAT_0095fba0 * (_DAT_0097189c + _DAT_0095fba0 * fVar2) +
          _DAT_0095fb98 * (_DAT_00971894 + fVar2 * _DAT_0095fb98) +
          _DAT_0095fb9c * (_DAT_00971898 + _DAT_0095fb9c * fVar2));
    _DAT_00963f84 =
         -(_DAT_0095fba0 * _DAT_0097189c +
          _DAT_00971898 * _DAT_0095fb9c + _DAT_00971894 * _DAT_0095fb98);
    uVar3 = FUN_005d9a00(&DAT_0080657c,&DAT_00806570,0xfffffffe);
    FUN_005ee250();
    uVar5 = 0;
    if (*(int *)(param_1 + 0x74) != 0) {
      iVar4 = 0;
      do {
        puVar1 = (uint *)(iVar4 + 0x10 + *(int *)(param_1 + 0x78));
        *puVar1 = *puVar1 & 0xfffffffb;
        uVar5 = uVar5 + 1;
        iVar4 = iVar4 + 0x18;
      } while (uVar5 < *(uint *)(param_1 + 0x74));
    }
    FUN_005ee940(param_1,uVar3,DAT_00971abc,0xffffffff,0);
    FUN_005ee710();
    return 1;
  }
  return 0;
}

