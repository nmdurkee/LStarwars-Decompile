/* Ghidra analysis pseudocode, not original source.
 * ev_8be49e78861dfe08cca82ea9c09c813f64ee3632778122cedbbea2ab2ea39171
 * Entry: 0x605220; label: FUN_00605220
 */

void FUN_00605220(char *param_1)

{
  char *pcVar1;
  undefined **local_c [3];
  
  if (param_1 == (char *)0x0) {
    pcVar1 = (char *)0x0;
  }
  else {
    pcVar1 = param_1;
    if ((uint)(0xffffffff / ZEXT48(param_1)) < 8) {
      param_1 = (char *)0x0;
      std::exception::exception((exception *)local_c,&param_1);
      local_c[0] = &PTR_FUN_0076a75c;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_c,&DAT_007eca48);
    }
  }
  FUN_006ea018((int)pcVar1 * 8);
  return;
}

