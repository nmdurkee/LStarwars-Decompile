/* Ghidra analysis pseudocode, not original source.
 * ev_c81f74825c4c1caab95b487b54d809df2f5062ed260a25fe246075816e66607e
 * Entry: 0x5e0f90; label: FUN_005e0f90
 */

void FUN_005e0f90(byte *param_1,int param_2)

{
  code *pcVar1;
  
  do {
    switch(param_1[1]) {
    case 1:
      param_1 = *(byte **)(param_1 + 4);
      break;
    default:
      do {
      } while( true );
    case 3:
      pcVar1 = *(code **)(param_2 + -0x200 + (uint)*param_1 * 4);
      if (pcVar1 != (code *)0x0) {
        (*pcVar1)(*(undefined4 *)(param_1 + 4));
      }
    case 0:
      param_1 = param_1 + 0x10;
      break;
    case 4:
      return;
    }
  } while( true );
}

