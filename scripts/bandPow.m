function p = bandPow(x, fs, lo, hi) %#codegen
% Power of x between lo and hi Hz (same idea as bandpower, codegen-friendly)
N  = numel(x);
X  = fft(x(:));
P  = abs(X(1:floor(N/2)+1)).^2 / (fs*N);
P(2:end-1) = 2*P(2:end-1);
f  = (0:floor(N/2))' * fs / N;
p  = sum(P(f >= lo & f <= hi)) * fs / N;
end