/* Ghidra analysis pseudocode, not original source.
 * ev_7cebcd231b4f420658515fe731eecd90e8f898d61da81d56368ea9915da5e025
 * Entry: 0x595a10; label: FUN_00595a10
 */

void FUN_00595a10(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = 0;
  do {
    *(undefined4 *)(iVar1 + 0xe04 + DAT_0093d504) = 0xffffffff;
    iVar1 = iVar1 + 0x10d8;
  } while (iVar1 < 0x43600);
  iVar1 = 0;
  if (0 < DAT_0093d500) {
    piVar3 = (int *)(DAT_0093d504 + 0xe04);
    do {
      if (((piVar3[-0x302] & 1U) != 0) && ((piVar3[-0x302] & 0x1000U) != 0)) {
        iVar2 = FUN_00635660();
        *piVar3 = iVar2;
        if (iVar2 != -1) {
          FUN_006357f0(iVar2,2);
          FUN_00635970(*piVar3,0);
        }
      }
      iVar1 = iVar1 + 1;
      piVar3 = piVar3 + 0x436;
    } while (iVar1 < DAT_0093d500);
  }
  return;
}

