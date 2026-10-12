/* Ghidra pseudocode, not original source.
 * ev_3ac53ec2c8a91968fde67182539679734e70c7e49df6a3287feb2aec240cddbe
 * Entry: 0x429050; label: FUN_00429050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00429050(int param_1,undefined4 param_2,undefined4 param_3,undefined2 *param_4)

{
  int iVar1;
  
  if (param_1 == 0) {
    param_1 = FUN_0055f450();
  }
  iVar1 = FUN_00402e00(param_1,param_2,0,0);
  if (iVar1 != 0) {
    FUN_00403300(iVar1,param_3);
    if (param_4 != (undefined2 *)0x0) {
      *param_4 = *(undefined2 *)(iVar1 + 0x5c);
    }
    return 1;
  }
  return 0;
}

