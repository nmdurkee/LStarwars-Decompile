/* Ghidra analysis pseudocode, not original source.
 * ev_b8d156e74790e07078a260599393ca89d6d858c624833fd21a4e8cf1d6239801
 * Entry: 0x6ce200; label: FUN_006ce200
 */

void FUN_006ce200(void)

{
  int *piVar1;
  int in_ECX;
  undefined4 local_c;
  int *local_8;
  undefined4 local_4;
  
  for (piVar1 = *(int **)(in_ECX + 0x8c); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[0xb]) {
    if (piVar1[10] == 0) {
      if ((piVar1[0x30] == 0) && ((*(int *)(in_ECX + 0x98) == 0 || (DAT_02974c98 == 0)))) {
        if ((*(int *)(in_ECX + 0x9c) != 0) && (DAT_02974c98 != 0)) {
          local_c = *(undefined4 *)(in_ECX + -8);
          local_4 = 0;
          local_8 = piVar1;
          FUN_006c94a0(&local_c,0x80808080);
        }
      }
      else {
        FUN_006ba6a0(0);
        (**(code **)(*piVar1 + 0x38))(0);
        if (DAT_02973a60 != 0) {
          if ((DAT_02973a60 == 2) || (DAT_02973a60 == 3)) {
            FUN_006009c0();
          }
          DAT_02973a60 = 0;
        }
      }
    }
  }
  return;
}

