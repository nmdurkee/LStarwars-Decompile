/* Ghidra pseudocode, not original source.
 * ev_da30da9df459bd28e82b339ffdc0f4cd1266c83ded903d656831cff2a8a86063
 * Entry: 0x46d8f0; label: FUN_0046d8f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0046d8f0(void)

{
  undefined4 *in_EAX;
  int in_ECX;
  
  *in_EAX = *(undefined4 *)(in_ECX + 0x50);
  in_EAX[1] = *(undefined4 *)(in_ECX + 0x54);
  in_EAX[2] = *(undefined4 *)(in_ECX + 0x58);
  if (*(char *)(in_ECX + 0x61) == '\x02') {
    in_EAX[1] = (float)in_EAX[1] + 0.245;
    in_EAX[2] = (float)in_EAX[2] - 0.19;
  }
  else if (*(char *)(in_ECX + 0x61) == '\x03') {
    in_EAX[1] = (float)in_EAX[1] + 0.34;
    in_EAX[2] = (float)in_EAX[2] - 0.17;
    return;
  }
  return;
}

