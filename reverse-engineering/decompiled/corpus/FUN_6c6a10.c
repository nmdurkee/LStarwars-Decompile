/* Ghidra analysis pseudocode, not original source.
 * ev_b11735056f517841e68fc69c6a59e9f65c2ea93b1b22364b6a9fa70acd21d770
 * Entry: 0x6c6a10; label: FUN_006c6a10
 */

undefined4 FUN_006c6a10(undefined4 *param_1,undefined4 param_2,uint param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 8);
  do {
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    if ((int)puVar1[7] < 0) {
      if (param_4 != 0) {
        uVar2 = (**(code **)*puVar1)(param_2);
        iVar3 = FUN_006c6a10(param_1,uVar2,param_3,1);
        if (iVar3 != 0) {
          return 1;
        }
      }
    }
    else if ((param_3 & puVar1[7]) != 0) {
      *param_1 = param_2;
      param_1[1] = puVar1;
      return 1;
    }
    puVar1 = (undefined4 *)puVar1[1];
  } while( true );
}

