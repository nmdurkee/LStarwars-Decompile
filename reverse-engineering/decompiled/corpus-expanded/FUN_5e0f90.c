/* Ghidra pseudocode, not original source.
 * ev_a87fd181e19a595ed696a9e48a76c3177ea695d31392ba84c3867c15109a72c3
 * Entry: 0x5e0f90; label: FUN_005e0f90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

