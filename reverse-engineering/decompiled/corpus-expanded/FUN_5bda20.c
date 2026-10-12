/* Ghidra pseudocode, not original source.
 * ev_71ce34dfbc3e25ecc670a7014d4d5fe50c303635112430d697820e3c5a49cfb6
 * Entry: 0x5bda20; label: FUN_005bda20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005bda20(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_194;
  undefined1 local_190 [400];
  
  local_194 = 1;
  FUN_005bd7a0(param_1,local_190,100);
  iVar1 = FUN_004fa5f0(param_2,1);
  if (iVar1 != 0) {
    FUN_004f03d0(iVar1,&local_194,4);
    FUN_004f03d0(iVar1,param_1,0x5c);
    FUN_004f03d0(iVar1,local_190,400);
    FUN_004f99e0(iVar1);
    return 1;
  }
  return 0;
}

