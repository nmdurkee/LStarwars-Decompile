/* Ghidra analysis pseudocode, not original source.
 * ev_ec9281a2aa4ea110a1eb16e51d284c9eba7f36598b96ab7e95af51b91ca91f37
 * Entry: 0x741640; label: FUN_00741640
 */

void FUN_00741640(int param_1)

{
  if ((*(int *)(DAT_0297cc6c + 0x79188) != param_1) &&
     (*(int *)(DAT_0297cc6c + 0x79188) = param_1, param_1 != 0)) {
    FUN_006e5700(*(undefined4 *)(param_1 + 0x4cc));
    FUN_006e5290();
    return;
  }
  return;
}

