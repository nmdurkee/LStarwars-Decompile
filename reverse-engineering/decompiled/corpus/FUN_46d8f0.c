/* Ghidra analysis pseudocode, not original source.
 * ev_656543c8328aa29e7546f4f9ed4e60ad4c1e465caa45a29e90694e112f58dfef
 * Entry: 0x46d8f0; label: FUN_0046d8f0
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

