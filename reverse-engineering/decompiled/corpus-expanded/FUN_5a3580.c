/* Ghidra pseudocode, not original source.
 * ev_1147004b9dc166d1e84637369286a2c1a549644e29d4b7aad5b4a967d59cac62
 * Entry: 0x5a3580; label: FUN_005a3580
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a3580(void)

{
  int *in_EAX;
  
  if ((int *)in_EAX[1] == (int *)0x0) {
    DAT_0095da40 = *in_EAX;
  }
  else {
    *(int *)in_EAX[1] = *in_EAX;
  }
  if (*in_EAX != 0) {
    *(int *)(*in_EAX + 4) = in_EAX[1];
    *in_EAX = (int)DAT_0095da3c;
    DAT_0095da3c = in_EAX;
    return;
  }
  *in_EAX = (int)DAT_0095da3c;
  DAT_0095da3c = in_EAX;
  return;
}

