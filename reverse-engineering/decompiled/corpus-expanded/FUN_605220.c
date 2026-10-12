/* Ghidra pseudocode, not original source.
 * ev_c781f6f2f7d78097ae9ff869f9175a8231755f2e9224784a2b208dfae7521271
 * Entry: 0x605220; label: FUN_00605220
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

