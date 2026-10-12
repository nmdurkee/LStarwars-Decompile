/* Ghidra pseudocode, not original source.
 * ev_e349fb5d4996fa1cecd3bcddaaa967a101a71b87d72fe496b907a3d03e81288d
 * Entry: 0x60d1a0; label: FUN_0060d1a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060d1a0(void)

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

