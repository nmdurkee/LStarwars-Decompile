/* Ghidra analysis pseudocode, not original source.
 * ev_51d776bbf7e198208a4486308eec4a97f7acd5ccc3951e1c43c2ae0a52a9ca8f
 * Entry: 0x6c5b50; label: FUN_006c5b50
 */

undefined4 * FUN_006c5b50(undefined4 *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  do {
    if (param_1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    iVar1 = 0;
    if (0 < (int)param_1[0x1c]) {
      piVar2 = param_1 + 5;
      do {
        if (*(int *)(param_2 + 0xc) == *piVar2) {
          return param_1;
        }
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 3;
      } while (iVar1 < (int)param_1[0x1c]);
    }
    param_1 = (undefined4 *)*param_1;
  } while( true );
}

