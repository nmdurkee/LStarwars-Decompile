/* Ghidra pseudocode, not original source.
 * ev_da30da9df459bd28e82b339ffdc0f4cd1266c83ded903d656831cff2a8a86063
 * Entry: 0x46f6f0; label: FUN_0046f6f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0046f6f0(int param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    if ((param_1 != 0) &&
       ((*(char *)(param_1 + 0x61) == '\x03' || (*(char *)(param_1 + 0x61) == '\x02')))) {
      FUN_0046dc10(param_1,param_2,0);
      return;
    }
    *param_2 = *(undefined4 *)(param_1 + 100);
    param_2[1] = *(undefined4 *)(param_1 + 0x68);
    param_2[2] = *(undefined4 *)(param_1 + 0x6c);
  }
  return;
}

