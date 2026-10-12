/* Ghidra pseudocode, not original source.
 * ev_0e37ff2b068f2f451a629821c3494056628992f54992bdfe8536c4096373c130
 * Entry: 0x4ea890; label: FUN_004ea890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ea890(float param_1)

{
  if (0.0 < _DAT_0088a648) {
    _DAT_0088a648 = _DAT_0088a648 - param_1;
  }
  if (_DAT_0088a64c <= 0.0) {
    return;
  }
  _DAT_0088a64c = _DAT_0088a64c - param_1;
  return;
}

