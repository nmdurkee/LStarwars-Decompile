/* Ghidra pseudocode, not original source.
 * ev_0733f146760cc31006e6190a74f2cd28d34a83dcf7f13916827ecd624512e4e0
 * Entry: 0x5f0d70; label: FUN_005f0d70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f0d70(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  FUN_004ffaa0(DAT_00973fa4);
  FUN_005de440();
  FUN_00603920();
  FUN_005e0bd0();
  iVar3 = 0;
  if (0 < DAT_009739b8) {
    piVar2 = &DAT_009739bc;
    do {
      iVar1 = *piVar2;
      if ((*(byte *)(iVar1 + 0x74) & 4) != 0) {
        FUN_005df910();
        FUN_005df880();
      }
      if ((*(byte *)(iVar1 + 0x74) & 6) != 0) {
        FUN_005e0bd0();
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar3 < DAT_009739b8);
  }
  _DAT_00973f34 = DAT_00973ed4;
  _DAT_00973f38 = DAT_00973ed8;
  _DAT_00973f3c = DAT_00973edc;
  _DAT_00973f40 = DAT_00973ee0;
  _DAT_00973f44 = DAT_00973ee4;
  _DAT_00973f48 = DAT_00973ee8;
  _DAT_00973f4c = DAT_00973eec;
  _DAT_00973f50 = DAT_00973ef0;
  _DAT_00973f54 = DAT_00973ef4;
  _DAT_00973f58 = DAT_00973ef8;
  _DAT_00973f5c = DAT_00973efc;
  _DAT_00973f60 = DAT_00973f00;
  _DAT_00973f64 = DAT_00973f04;
  _DAT_00973f68 = DAT_00973f08;
  _DAT_00973f6c = DAT_00973f0c;
  _DAT_00973f70 = DAT_00973f10;
  _DAT_00973f74 = DAT_00973f14;
  _DAT_00973f78 = DAT_00973f18;
  _DAT_00973f7c = DAT_00973f1c;
  _DAT_00973f80 = DAT_00973f20;
  _DAT_00973f84 = DAT_00973f24;
  _DAT_00973f88 = DAT_00973f28;
  _DAT_00973f8c = DAT_00973f2c;
  _DAT_00973f90 = DAT_00973f30;
  FUN_005e0d00();
  FUN_004ffac0(DAT_00973fa4);
  return;
}

