/* Ghidra pseudocode, not original source.
 * ev_c97b225204041db9abadf07c9fc18e64db4e00ddeb87fb2f1b5eee4128d34da7
 * Entry: 0x74d7e0; label: FUN_0074d7e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0074d7e0(void)

{
  undefined1 local_44 [4];
  undefined1 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined **local_28 [4];
  undefined1 local_18;
  undefined4 local_8;
  undefined4 local_4;
  
  local_2c = 0xf;
  local_30 = 0;
  local_40 = 0;
  FUN_0060ccb0("vector<T> too long",0x12);
  FUN_006e9c07();
  local_28[0] = &PTR_FUN_0076a8cc;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_0060cb30(local_44,0,0xffffffff);
  local_28[0] = &PTR_FUN_0076a8d8;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_28,&DAT_007ecc88);
}

