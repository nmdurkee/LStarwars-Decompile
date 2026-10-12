/* Ghidra pseudocode, not original source.
 * ev_428398453750e294ede80d9f87d5cfcdf804466d2d70f27e1ba752c78f326fd9
 * Entry: 0x40aa90; label: FUN_0040aa90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0040aa90(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *unaff_ESI;
  
  unaff_ESI[2] = 0;
  unaff_ESI[1] = 0;
  *unaff_ESI = 0;
  iVar1 = 0;
  piVar2 = &DAT_0093d7f0;
  do {
    if ((*piVar2 != 0) && (((*(byte *)(*piVar2 + 0x1fc) & 0x80) != 0 || (DAT_00925398 != 0)))) {
      FUN_0040a570(param_1);
      FUN_005b37d0();
      iVar1 = iVar1 + 1;
    }
    piVar2 = piVar2 + 1;
  } while ((int)piVar2 < 0x93d7f8);
  if (0 < iVar1) {
    FUN_005b3830();
  }
  return;
}

