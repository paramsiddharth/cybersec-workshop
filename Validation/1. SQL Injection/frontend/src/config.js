let backendUrl = import.meta.env.VITE_BACKEND;
if (backendUrl.charAt(backendUrl.length - 1) !== '/')
	backendUrl += '/';

export const BACKEND = backendUrl;