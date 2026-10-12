/* Ghidra analysis pseudocode, not original source.
 * ev_1c7a82f294435201fd9406ba2f36685e25c9dd11fb4cb3b46f5b103b3befd94c
 * Entry: 0x6051c0; label: FUN_006051c0
 */

void FUN_006051c0(char *param_1)

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

