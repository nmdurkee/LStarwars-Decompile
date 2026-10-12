/* Ghidra analysis pseudocode, not original source.
 * ev_7cebcd231b4f420658515fe731eecd90e8f898d61da81d56368ea9915da5e025
 * Entry: 0x5967b0; label: FUN_005967b0
 */

int FUN_005967b0(float *param_1)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  undefined4 *unaff_EDI;
  
  *unaff_EDI = DAT_0095e5c8;
  unaff_EDI[1] = DAT_0095e5cc;
  unaff_EDI[2] = DAT_0095e5d0;
  *param_1 = -1.0;
  iVar2 = 0;
  piVar3 = &DAT_0093d7f0;
  do {
    if ((*piVar3 != 0) && ((*(byte *)(*piVar3 + 0x1fc) & 0x80) != 0)) {
      FUN_005b37d0();
      if (*param_1 <= *(float *)(*piVar3 + 0x608)) {
        fVar1 = *(float *)(*piVar3 + 0x608);
      }
      else {
        fVar1 = *param_1;
      }
      iVar2 = iVar2 + 1;
      *param_1 = fVar1;
    }
    piVar3 = piVar3 + 1;
  } while ((int)piVar3 < 0x93d7f8);
  if (0 < iVar2) {
    FUN_005b3830();
  }
  return iVar2;
}

