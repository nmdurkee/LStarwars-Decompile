/* Ghidra analysis pseudocode, not original source.
 * ev_7885ce39b81f670d8e3218fe7ff5fd78bd200dfae790f8ac5e62a68993a50c0e
 * Entry: 0x55bdc0; label: FUN_0055bdc0
 */

void FUN_0055bdc0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 int param_5,int param_6)

{
  int iVar1;
  
  if (param_5 != 0) {
    iVar1 = FUN_0057e710();
    if (((iVar1 != 0) && (param_6 != -1)) && (param_6 * 0x9c + DAT_00951354 != DAT_00951364)) {
      param_5 = 0;
    }
  }
  FUN_0062d540(param_1,param_2,param_3,*param_4,param_5);
  return;
}

